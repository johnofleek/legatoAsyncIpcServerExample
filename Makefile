APPNAME :=asyncipctest
TARGET_IP:=192.168.2.2

localhost: app.localhost

#ar7: app.ar7

wp7: app.wp7

#ar86: app.ar86

wp85: app.wp85

i85: ap.wp85

app.%:
	mkapp $(APPNAME).adef -t $* -v

ap.%:
	mkapp $(APPNAME).adef -t $* -v
	app install $(APPNAME).wp85.update $(TARGET_IP)	

clean:
	rm -rf _build_* *.update

install:
	app install $(APPNAME).wp85.update $(TARGET_IP)
start:
	app start $(APPNAME) $(TARGET_IP)
stop:	
	app stop $(APPNAME) $(TARGET_IP)
	
	
	
