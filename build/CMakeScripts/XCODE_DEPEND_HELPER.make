# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.testCases.Debug:
PostBuild.utils.Debug: /Users/steph/Documents/Programming/baseProject/build/test/Debug/testCases
/Users/steph/Documents/Programming/baseProject/build/test/Debug/testCases:\
	/opt/local/lib/libgtest.a\
	/Users/steph/Documents/Programming/baseProject/build/lib/Debug/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/test/Debug/testCases


PostBuild.testProjectExe.Debug:
PostBuild.utils.Debug: /Users/steph/Documents/Programming/baseProject/build/app/Debug/testProjectExe
/Users/steph/Documents/Programming/baseProject/build/app/Debug/testProjectExe:\
	/Users/steph/Documents/Programming/baseProject/build/lib/Debug/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/app/Debug/testProjectExe


PostBuild.utils.Debug:
/Users/steph/Documents/Programming/baseProject/build/lib/Debug/libutils.a:
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/lib/Debug/libutils.a


PostBuild.testCases.Release:
PostBuild.utils.Release: /Users/steph/Documents/Programming/baseProject/build/test/Release/testCases
/Users/steph/Documents/Programming/baseProject/build/test/Release/testCases:\
	/opt/local/lib/libgtest.a\
	/Users/steph/Documents/Programming/baseProject/build/lib/Release/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/test/Release/testCases


PostBuild.testProjectExe.Release:
PostBuild.utils.Release: /Users/steph/Documents/Programming/baseProject/build/app/Release/testProjectExe
/Users/steph/Documents/Programming/baseProject/build/app/Release/testProjectExe:\
	/Users/steph/Documents/Programming/baseProject/build/lib/Release/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/app/Release/testProjectExe


PostBuild.utils.Release:
/Users/steph/Documents/Programming/baseProject/build/lib/Release/libutils.a:
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/lib/Release/libutils.a


PostBuild.testCases.MinSizeRel:
PostBuild.utils.MinSizeRel: /Users/steph/Documents/Programming/baseProject/build/test/MinSizeRel/testCases
/Users/steph/Documents/Programming/baseProject/build/test/MinSizeRel/testCases:\
	/opt/local/lib/libgtest.a\
	/Users/steph/Documents/Programming/baseProject/build/lib/MinSizeRel/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/test/MinSizeRel/testCases


PostBuild.testProjectExe.MinSizeRel:
PostBuild.utils.MinSizeRel: /Users/steph/Documents/Programming/baseProject/build/app/MinSizeRel/testProjectExe
/Users/steph/Documents/Programming/baseProject/build/app/MinSizeRel/testProjectExe:\
	/Users/steph/Documents/Programming/baseProject/build/lib/MinSizeRel/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/app/MinSizeRel/testProjectExe


PostBuild.utils.MinSizeRel:
/Users/steph/Documents/Programming/baseProject/build/lib/MinSizeRel/libutils.a:
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/lib/MinSizeRel/libutils.a


PostBuild.testCases.RelWithDebInfo:
PostBuild.utils.RelWithDebInfo: /Users/steph/Documents/Programming/baseProject/build/test/RelWithDebInfo/testCases
/Users/steph/Documents/Programming/baseProject/build/test/RelWithDebInfo/testCases:\
	/opt/local/lib/libgtest.a\
	/Users/steph/Documents/Programming/baseProject/build/lib/RelWithDebInfo/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/test/RelWithDebInfo/testCases


PostBuild.testProjectExe.RelWithDebInfo:
PostBuild.utils.RelWithDebInfo: /Users/steph/Documents/Programming/baseProject/build/app/RelWithDebInfo/testProjectExe
/Users/steph/Documents/Programming/baseProject/build/app/RelWithDebInfo/testProjectExe:\
	/Users/steph/Documents/Programming/baseProject/build/lib/RelWithDebInfo/libutils.a
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/app/RelWithDebInfo/testProjectExe


PostBuild.utils.RelWithDebInfo:
/Users/steph/Documents/Programming/baseProject/build/lib/RelWithDebInfo/libutils.a:
	/bin/rm -f /Users/steph/Documents/Programming/baseProject/build/lib/RelWithDebInfo/libutils.a




# For each target create a dummy ruleso the target does not have to exist
/Users/steph/Documents/Programming/baseProject/build/lib/Debug/libutils.a:
/Users/steph/Documents/Programming/baseProject/build/lib/MinSizeRel/libutils.a:
/Users/steph/Documents/Programming/baseProject/build/lib/RelWithDebInfo/libutils.a:
/Users/steph/Documents/Programming/baseProject/build/lib/Release/libutils.a:
/opt/local/lib/libgtest.a:
