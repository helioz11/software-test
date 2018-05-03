pipeline {
    agent {
        docker {
            image 'gcc'
        }
    }
    stages {
        stage('Build') {
            steps {
                sh 'make -C make'
            }
	}
	stage('Test') {
	    steps {
		sh 'make -C make ./triangle_unittest ./nextdate_unittest ./commission_unittest'
	    }
	}
    }
}
