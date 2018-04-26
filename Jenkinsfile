pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make -C makeFolderName'
            }
        }
    }
}
