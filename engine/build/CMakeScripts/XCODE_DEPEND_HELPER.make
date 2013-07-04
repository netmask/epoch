# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# For each target create a dummy rule so the target does not have to exist
/usr/local/lib/libsfml-system.dylib:
/usr/local/lib/libsfml-window.dylib:
/usr/local/lib/libsfml-graphics.dylib:
/usr/local/lib/libsfml-network.dylib:
/usr/local/lib/libsfml-audio.dylib:
/usr/local/lib/libv8.dylib:
/usr/local/lib/libreadline.dylib:


# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.epoch.Debug:
/Users/netmask/Projects/personal/epoch/engine/dist/Debug/epoch:\
	/usr/local/lib/libsfml-system.dylib\
	/usr/local/lib/libsfml-window.dylib\
	/usr/local/lib/libsfml-graphics.dylib\
	/usr/local/lib/libsfml-network.dylib\
	/usr/local/lib/libsfml-audio.dylib\
	/usr/local/lib/libv8.dylib\
	/usr/local/lib/libreadline.dylib
	/bin/rm -f /Users/netmask/Projects/personal/epoch/engine/dist/Debug/epoch


PostBuild.epoch.Release:
/Users/netmask/Projects/personal/epoch/engine/dist/Release/epoch:\
	/usr/local/lib/libsfml-system.dylib\
	/usr/local/lib/libsfml-window.dylib\
	/usr/local/lib/libsfml-graphics.dylib\
	/usr/local/lib/libsfml-network.dylib\
	/usr/local/lib/libsfml-audio.dylib\
	/usr/local/lib/libv8.dylib\
	/usr/local/lib/libreadline.dylib
	/bin/rm -f /Users/netmask/Projects/personal/epoch/engine/dist/Release/epoch


PostBuild.epoch.MinSizeRel:
/Users/netmask/Projects/personal/epoch/engine/dist/MinSizeRel/epoch:\
	/usr/local/lib/libsfml-system.dylib\
	/usr/local/lib/libsfml-window.dylib\
	/usr/local/lib/libsfml-graphics.dylib\
	/usr/local/lib/libsfml-network.dylib\
	/usr/local/lib/libsfml-audio.dylib\
	/usr/local/lib/libv8.dylib\
	/usr/local/lib/libreadline.dylib
	/bin/rm -f /Users/netmask/Projects/personal/epoch/engine/dist/MinSizeRel/epoch


PostBuild.epoch.RelWithDebInfo:
/Users/netmask/Projects/personal/epoch/engine/dist/RelWithDebInfo/epoch:\
	/usr/local/lib/libsfml-system.dylib\
	/usr/local/lib/libsfml-window.dylib\
	/usr/local/lib/libsfml-graphics.dylib\
	/usr/local/lib/libsfml-network.dylib\
	/usr/local/lib/libsfml-audio.dylib\
	/usr/local/lib/libv8.dylib\
	/usr/local/lib/libreadline.dylib
	/bin/rm -f /Users/netmask/Projects/personal/epoch/engine/dist/RelWithDebInfo/epoch


