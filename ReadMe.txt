This project was a means for me to practice and improve upon c++ features that I do not use often (in particular templates)


streams             -   output stream converts object to a stream of characters   
                        input stream does the opposite
        
templates           - evaluated at compile time. a template does not exist until we call it. the compiler creates the code based on usage.

virtual inheritance - multiple inheritance 'diamond problem'

grpc                - sample client & server


Update: I have started adding basic concepts to this work/collection in order to perhaps help others.



References, giving credit to those that deserve it..

Web sites:
https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-vs?pivots=shell-powershell
https://github.com/chungphb/grpc-cpp/blob/master/sample/sample_client.cc
https://www.youtube.com/watch?v=p3OQDb4nWfg&list=PLaeXzeqT5-_T21UjUX9nGMlLR0A2yvIWx&index=10


Books:
A Tour of C++, 3rd ed, Bjarne Stroustrup
C++ Templates: The Complete Guide, 2nd ed, Vandevoorde et al.

Github:
https://github.com/microsoft/vcpkg.git
https://github.com/gabime/spdlog.git
https://github.com/protocolbuffers/protobuf.git

Youtube:
https://www.youtube.com/watch?v=1MuwAZJpqFk (gRPC)





Project Setup:

Powershell:

$env:VCPKG_ROOT="D:\DEVELOPMENT\vcpkg"      - i.e. the path to your vcpkg folder
$env:PATH="$env:VCPKG_ROOT;$env:PATH"


From within the project folder:

vcpkg new --application
vcpkg add port fmt                          - this will create a vcpkg.json file which we will modify (below)


Configure the vcpkg.json file as follows:
{
  "dependencies": [
    "protobuf",
    "grpc"
  ]
}

Then type: 'vcpkg install' to install the project requirements        - approx 30 mins execution time
