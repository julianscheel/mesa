// Copyright (c) 2004-2020 Microchip Technology Inc. and its subsidiaries.
// SPDX-License-Identifier: MIT

properties([
        [$class: 'BuildDiscarderProperty', strategy: [$class: 'LogRotator', artifactDaysToKeepStr: '', artifactNumToKeepStr: '', daysToKeepStr: '5', numToKeepStr: '20']],
        [$class: 'GithubProjectProperty', projectUrlStr: 'https://bitbucket.microchip.com/scm/unge/sw-mesa.git'],
        [$class: 'ThrottleJobProperty', categories: [], limitOneJobWithMatchingParams: false, maxConcurrentPerNode: 0, maxConcurrentTotal: 1, paramsToUseForLimit: '', throttleEnabled: true, throttleOption: 'project']
        ])

node('blademaster') {
    try {
        stage("SCM Checkout") {
            checkout([
                $class: 'GitSCM',
                branches: scm.branches,
                doGenerateSubmoduleConfigurations: scm.doGenerateSubmoduleConfigurations,
                extensions: scm.extensions + [[$class: 'CloneOption', noTags: false, reference: '/gitref/mesa.git', shallow: false]],
                submoduleCfg: [],
                userRemoteConfigs: scm.userRemoteConfigs
            ])
            sh "git reset --hard; git clean -ffdx"
            sh "git lfs fetch"
            sh "git lfs checkout"
        }

        step([$class: 'GitHubSetCommitStatusBuilder', statusMessage: [content: 'Build in progress']])
        currentBuild.result = 'SUCCESS'
        try {
            stage("Build") {
                def git_id = sh(script: "git describe --tags --long", returnStdout: true).trim()
                def branch = env.BRANCH_NAME
                manager.addShortText("${git_id}@${branch}")
                sh "./.cmake/release.rb --simplegrid --internal-checks"
            }
        } catch (error) {
            currentBuild.result = 'FAILURE'
            throw error
        } finally {
            stage("Archiving results") {
                try {
                    archive 'images/**'
                } catch (error) {
                    currentBuild.result = 'FAILURE'
                    throw error
                }
            }
        }

        stage("Backwards compatibility") {
            try {
                sh "./.cmake/backwards-compatibility-check.rb"
            } catch (error) {
                currentBuild.result = 'FAILURE'
                throw error
            }
        }

    } catch(error) {
    } finally {
        step([
                $class: 'GitHubCommitStatusSetter',
                errorHandlers: [[$class: 'ShallowAnyErrorHandler']],
                statusResultSource: [
                $class: 'ConditionalStatusResultSource',
                results: [
                [$class: 'BetterThanOrEqualBuildResult', result: 'SUCCESS', state: 'SUCCESS', message: currentBuild.description],
                [$class: 'BetterThanOrEqualBuildResult', result: 'FAILURE', state: 'FAILURE', message: currentBuild.description],
                [$class: 'AnyBuildResult', state: 'FAILURE', message: 'Loophole']
                ]
                ]
        ])

        try {
            // Prevent this step from making the whole thing fail by encapsulating
            // it in a 'try' with an empty 'catch'
            step([$class: 'Mailer', notifyEveryUnstableBuild: true,
                  recipients: emailextrecipients([[$class: 'CulpritsRecipientProvider'],
                                                  [$class: 'RequesterRecipientProvider']])])
        } catch (Exception ex) {
        }
    }
}
