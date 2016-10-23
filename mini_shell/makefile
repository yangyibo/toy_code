bin: main.cpp  cmd.cpp cmdMgr.dll
	g++ $^ -L. -lcmdMgr -o $@


cmdMgr.dll: cmdMgr.cpp
	g++ $^ -Wl,--add-stdcall-alias -shared -o $@


clean:
	rm *.exe *.o *.dll