pipeline {
    agent any

    options {
        skipDefaultCheckout(true)
    }

    stages {
        
        stage('Build') {
            steps {
                git branch: 'main', url: 'file:///code'
                sh '''
                    mkdir -p build
                    cmake -S . -B build
                    cppcheck --enable=all --inconclusive --xml --xml-version=2 src test 2> cppcheck.xml
                '''
            }
        }

        stage('Code Analysis') {
            steps {
                publishCppcheck pattern:'cppcheck.xml'
            }
        }

        stage('Unit Test') {
            steps {
                sh "cd build && ctest"
            }
        }

        stage('Cucumber Test') {
            steps {
                sh '''
                    ./build/features/tempconv-steps &
                    cucumber features
                '''
            }
        }
    }
}