# Scope
Demo the .cdef server async function call pattern

```
provides:
{
    api:
    {
        async.api [async]
    }
}
```

# Plan
Done

# Summary


The async function call pattern works like this  

```
serverFunction()
{
   Dosomething
   async_TestRespond() // this makes the client get a function return 
                       //    so that calling functions event loop unblocks
   DoSomethingThatBlocks

   return when done    // - nothing passed back unless there is a callback event to call
}
```

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

** start the app (it has manual start set) **  

```
make start
```


# GIT  




## Git clone the project  

```
git clone https://github.com/johnofleek/legatoAsyncIpcServerExample
```


## Git "checkin"
```
git add .  
git commit -m "your comment"  
git push -u origin master  
```

## Git "checkout"
git pull origin master




