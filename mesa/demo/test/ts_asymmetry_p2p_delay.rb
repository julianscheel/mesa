#!/usr/bin/env ruby

# Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
# SPDX-License-Identifier: MIT

require_relative 'libeasy/et'
require_relative 'ts_lib'
require 'pry'

$ts = get_test_setup("mesa_pc_b2b_4x")

check_capabilities do
    $cap_family = $ts.dut.call("mesa_capability", "MESA_CAP_MISC_CHIP_FAMILY")
    assert(($cap_family == chip_family_to_id("MESA_CHIP_FAMILY_JAGUAR2")) || ($cap_family == chip_family_to_id("MESA_CHIP_FAMILY_SPARX5")),
           "Family is #{$cap_family} - must be #{chip_family_to_id("MESA_CHIP_FAMILY_JAGUAR2")} (Jaguar2) or #{chip_family_to_id("MESA_CHIP_FAMILY_SPARX5")} (SparX-5).")
    $cap_epid = $ts.dut.call("mesa_capability", "MESA_CAP_PACKET_IFH_EPID")
    $cap_core_clock = $ts.dut.call("mesa_capability", "MESA_CAP_INIT_CORE_CLOCK")
end

$cpu_queue = 7
$npi_port = 3
$port0 = 0
$port1 = 1
$port2 = 2
$vlan = 100
$acl_id = 1
$pcb = $ts.dut.pcb

def tod_asymmetry_p2p_delay_test
    test "tod_asymmetry_p2p_delay_test" do

    # Create IS2 to ONE-STEP SYNC frame
    conf = $ts.dut.call("mesa_ace_init", "MESA_ACE_TYPE_ETYPE")
    conf["id"] = $acl_id
    conf["port_list"] = "#{$ts.dut.port_list[$port0]}"
    action = conf["action"]
    action["ptp_action"] = "MESA_ACL_PTP_ACTION_ONE_STEP"
    $ts.dut.call("mesa_ace_add", 0, conf)

    lowest_corr_none = nano_corr_lowest_measure

    if ($cap_core_clock != 0)
        misc = $ts.dut.call("mesa_misc_get")
        exp_corr = (misc["core_clock_freq"] == "MESA_CORE_CLOCK_250MHZ") ? 2 : 1
    else
        exp_corr = ($cap_family == chip_family_to_id("MESA_CHIP_FAMILY_JAGUAR2")) ? 2 : 1
    end
    if ($pcb == 135)    #Test on Copper PHY
        if ((lowest_corr_none > 2300) || (lowest_corr_none < 1900))
            t_e("Unexpected correction field including egress delay. lowest_corr_none = #{lowest_corr_none}")
        end
    else
        if ((lowest_corr_none < 0) || ((lowest_corr_none / 1000) != exp_corr))
            t_e("Unexpected correction field including egress delay. lowest_corr_none = #{lowest_corr_none}")
        end
    end

    if ($cap_family == chip_family_to_id("MESA_CHIP_FAMILY_JAGUAR2"))
        diff_max = 520
    else
        diff_max = 100
    end
    if ($pcb == 135)    #Test on Copper PHY
        diff_max = 500
    end

    # Configure asymmetry delay. It is selected to be as large as possible but smaller than the lowest measured correction
    asymmetry = lowest_corr_none-100
    $ts.dut.call("mesa_ts_delay_asymmetry_set", $ts.dut.port_list[$port0], asymmetry<<16)
    $ts.dut.call("mesa_ts_delay_asymmetry_set", $ts.dut.port_list[$port1], asymmetry<<16)

    # Change IS2 to ONE-STEP add egress delay SYNC frame
    action["ptp_action"] = "MESA_ACL_PTP_ACTION_ONE_STEP_ADD_DELAY"
    $ts.dut.call("mesa_ace_add", 0, conf)

    lowest_corr_eg = nano_corr_lowest_measure
    diff0 = (lowest_corr_eg - (lowest_corr_none - asymmetry))

    # The asymmetry delay is subtracted from correction on egress 
    t_i("lowest_corr_none = #{lowest_corr_none}  lowest_corr_eg = #{lowest_corr_eg}  diff #{diff0}")
    if ((lowest_corr_none < lowest_corr_eg) || (diff0 < -diff_max) || (diff0 > diff_max))
        t_e("Unexpected correction field including egress delay.")
    end

    # Change IS2 to ONE-STEP add ingress delay 1 SYNC frame
    action["ptp_action"] = "MESA_ACL_PTP_ACTION_ONE_STEP_SUB_DELAY_1"
    $ts.dut.call("mesa_ace_add", 0, conf)

    lowest_corr_in1 = nano_corr_lowest_measure
    diff1 = (lowest_corr_in1 - (lowest_corr_none + asymmetry))

    # The asymmetry delay is added to correction on ingress 
    t_i("lowest_corr_none = #{lowest_corr_none}  lowest_corr_in1 = #{lowest_corr_in1}  diff #{diff1}")
    if ((lowest_corr_in1 < lowest_corr_none) || (diff1 < -diff_max) || (diff1 > diff_max))
        t_e("Unexpected correction field including egress delay.")
    end

    # Change IS2 to ONE-STEP add ingress delay 2 SYNC frame
    action["ptp_action"] = "MESA_ACL_PTP_ACTION_ONE_STEP_SUB_DELAY_2"
    $ts.dut.call("mesa_ace_add", 0, conf)

    lowest_corr_in2 = nano_corr_lowest_measure
    diff2 = (lowest_corr_in2 - (lowest_corr_none + asymmetry))

    # The asymmetry + p2p delay is added to correction on ingress. The p2p delay is zero at this point.
    t_i("lowest_corr_none = #{lowest_corr_none}  lowest_corr_in2 = #{lowest_corr_in2}  diff #{diff2}")
    if ((lowest_corr_in2 < lowest_corr_none) || (diff2 < -diff_max) || (diff2 > diff_max))
        t_e("Unexpected correction field including egress delay.")
    end

    # Configure p2p delay. It is selected to be as large as possible but smaller than the lowest measured correction
    $ts.dut.call("mesa_ts_p2p_delay_set", $ts.dut.port_list[$port0], asymmetry<<16)

    lowest_corr_in2 = nano_corr_lowest_measure
    diff3 = (lowest_corr_in2 - (lowest_corr_none + 2*asymmetry))

    # The asymmetry + p2p delay is added to correction on ingress 
    t_i("lowest_corr_in1 = #{lowest_corr_in1}  lowest_corr_in2 = #{lowest_corr_in2}  diff #{diff3}")
    if ((lowest_corr_in2 < lowest_corr_in1) || (diff3 < -diff_max) || (diff3 > diff_max))
        t_e("Unexpected correction field including egress delay.")
    end

    t_i ("diff_max #{diff_max} diff0 #{diff0} diff1 #{diff1} diff2 #{diff2} diff3 #{diff3}")
    end
end

test "test_config" do
    # disable VLAN 1 to avoid looping
    $ts.dut.call("mesa_vlan_port_members_set", 1, "")

    # Flush MAC table
    $ts.dut.call("mesa_mac_table_flush")

    # CPU queue configuration
    $packet_rx_conf_restore = $ts.dut.call("mesa_packet_rx_conf_get")
    conf = $packet_rx_conf_restore.dup
    conf["queue"][$cpu_queue]["npi"]["enable"] = true
    $ts.dut.call("mesa_packet_rx_conf_set", conf)

    # NPI port configuration save
    $npi_conf_restore = $ts.dut.call("mesa_npi_conf_get")
    conf = $npi_conf_restore.dup
    conf["enable"] = true
    conf["port_no"] = $ts.dut.port_list[$npi_port]
    $ts.dut.call("mesa_npi_conf_set", conf)

    # Set VLAN port configuration
    $vlan_port_conf_restore0 = $ts.dut.call("mesa_vlan_port_conf_get", $ts.dut.port_list[$port0])
    conf = $vlan_port_conf_restore0.dup
    conf["port_type"] = "MESA_VLAN_PORT_TYPE_UNAWARE"
    conf["pvid"] = $vlan
    conf["untagged_vid"] = $vlan
    conf["frame_type"] = "MESA_VLAN_FRAME_ALL"
    $ts.dut.call("mesa_vlan_port_conf_set", $ts.dut.port_list[$port0], conf)

    $vlan_port_conf_restore1 = $ts.dut.call("mesa_vlan_port_conf_get", $ts.dut.port_list[$port1])
    conf = $vlan_port_conf_restore1.dup
    conf["port_type"] = "MESA_VLAN_PORT_TYPE_UNAWARE"
    conf["pvid"] = $vlan
    conf["untagged_vid"] = $vlan
    conf["frame_type"] = "MESA_VLAN_FRAME_ALL"
    $ts.dut.call("mesa_vlan_port_conf_set", $ts.dut.port_list[$port1], conf)

    # Set VLAN memberships
    port_list = "#{$ts.dut.port_list[$port0]},#{$ts.dut.port_list[$port1]}"
    $ts.dut.call("mesa_vlan_port_members_set", $vlan, port_list)

    $asymmetry_conf_restore0 = $ts.dut.call("mesa_ts_delay_asymmetry_get", $ts.dut.port_list[$port0])
    $asymmetry_conf_restore1 = $ts.dut.call("mesa_ts_delay_asymmetry_get", $ts.dut.port_list[$port1])

    $p2p_conf_restore = $ts.dut.call("mesa_ts_p2p_delay_get", $ts.dut.port_list[$port0])
end

test "test_run" do
    # Test egress and ingress asymmetry and p2p delay
    tod_asymmetry_p2p_delay_test
end

test "test_clean_up" do
    # Delete ACE rule
    $ts.dut.call("mesa_ace_del", $acl_id)

    # VLAN port configuration restore
    $ts.dut.call("mesa_vlan_port_conf_set", $ts.dut.port_list[$port0], $vlan_port_conf_restore0)
    $ts.dut.call("mesa_vlan_port_conf_set", $ts.dut.port_list[$port1], $vlan_port_conf_restore1)

    # Clear VLAN memberships
    $ts.dut.call("mesa_vlan_port_members_set", $vlan, "")

    # CPU queue configuration restore
    $ts.dut.call("mesa_packet_rx_conf_set", $packet_rx_conf_restore)

    # NPI port configuration restore
    $ts.dut.call("mesa_npi_conf_set", $npi_conf_restore)

    # Asymmetry delay restore
    $ts.dut.call("mesa_ts_delay_asymmetry_set", $ts.dut.port_list[$port0], $asymmetry_conf_restore0)
    $ts.dut.call("mesa_ts_delay_asymmetry_set", $ts.dut.port_list[$port1], $asymmetry_conf_restore1)

    # p2p delay restore
    $ts.dut.call("mesa_ts_p2p_delay_set", $ts.dut.port_list[$port0], $p2p_conf_restore)
end

