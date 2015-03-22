CC = g++
COMPILERFLAGS = -I. -I /boot/develop/headers/be -I .. 
LINKERFLAGS = -L. -L /boot/develop/lib/x86   -lbe -ltranslation -lroot


# $@ refers to the make command, $^ refers to all the dependencies for that command
#$< refers to the first dependency for that command


#Main App skeleton below

HSVDemo:  HSVDemoApplication.o MainWindow.o TempView.o HidingScrollView.o HidingScrollBar.o main.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $^ $(LINKERFLAGS) -o $@

#End of Main App skeleton

#Supporting classes & files

HSVDemoApplication.o: ./HSVDemoApplication.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $< -o $@ -c 
	

MainWindow.o: ./MainWindow.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $< -o $@ -c 
	
TempView.o: ./TempView.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $< -o $@ -c 

HidingScrollBar.o: ../HidingScrollBar.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $< -o $@ -c 

HidingScrollView.o: ../HidingScrollView.cpp
	@echo --- $@ ---
	$(CC) $(COMPILERFLAGS) $< -o $@ -c 
	 
	
clean:
	@echo --- $@ ---
	rm -f ./HSVDemo
	rm -f ./*.o
