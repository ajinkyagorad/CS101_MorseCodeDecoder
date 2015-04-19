This folder contains the source files for project.
 It requires atmel studio6.0 
project file : MorseCodeDecoder.atsln 

Steps to  build the program:

	Open the project file .atsln .
	Try to build the project, if it shows the build error on the first place then ,
	
	1.Create a new project file with atmel GCC executable  C++ Project with device ATmega2560 ( or any other suitable device )
	2. copy all the source files from the folder MorseCodeDecoder in this directory to the directory where the project created. ie if project  name is  prj_name then directory to which it should be copied be ..your_atmel_studio_project_directory/prj_name/prj_name/
	3. after copying files go to solution explorer, right click on prj_name -select add- existing items
		select all items except Debug(if exists) and .cppproj file.
	4. now try compiling project.