# Scope
A Legato service - Mqtt client

At legato MQTT client service is provided by embedding the wolf mqtt library.

# Plan
Provide the ability to send mqtt data
Provide the ability to subscribe to mqtt data
One server URL supported at a time
Lower level IP connectivity issues are reported to external apps using this service
Errors can be cleaned up and MQTT connectivity resumed


# Legato Command line build

From project root  

**Set the cross build environment**  

source ~/legato/packages/legato.sdk.latest/resources/configlegatoenv

**Build for wp85**  

```
make wp85
```


** install from host (assumes target is 192.168.2.2)**  


```
make install 
```

# GIT  

This project has a nmber of dependancies

## Required structure is

aFolder/legatoMqttClientWolf  
aFolder/legatoMqttClientWolf/wolfMQTT  
afolder/legatoNet  (for the api and service needs to be on the target)  



## Git clone the project  

```
git clone https://gitlab.com/johnofleek/legatoMqttClientWolf.git
```

Wolf MQTT into project root folder /wolfMQTT
```
git clone https://github.com/wolfSSL/wolfMQTT.git
```

Net service - this is to workaround the getaddrinfo() sandbox issue (see below)
```
git clone https://github.com/johnofleek/legatoNet.git
```

## Git "checkin"
```
git add .  
git commit -m "your comment"  
git push -u origin master  
```

## Git "checkout"
git pull origin master

# Notes on building wolf mqtt for Legato

## MqttClient_Connect() fails due to #define WOLFMQTT_NO_STDIN_CAP

Added WOLFMQTT_NO_STDIN_CAP as a compile option -D in Component.cdef  
-- this is needed I don't know what STDIO doesbut without it the following call returns -102  which is waiting on STDIO -
 I don't know what wolfs' intention was

```
MqttClient_Connect(&mqttCtx->client, &mqttCtx->connect); 
```


## /examples/mqttnet.c->NetConnect() fails when app is sandboxed

This is because NetConnect uses getaddrinfo() from libc and for some reason the sandboxed app isn't able to execute it correctly (permissions??)

Libc is accessable in the sandbox by default [link](http://legato.io/legato-docs/latest/howToPortLegacyC.html "legato doc")

To work around this legatoNet was created - the intention is to build all odd stuff that won't run in a sandbox into this service.
Todo add the ntp stuff to this service


