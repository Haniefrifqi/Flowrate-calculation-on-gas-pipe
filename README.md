# Flowrate-calculation-on-gas-pipe

This system will show how flowrate calculation system work. This system implemented on arduino code, proteus simulator, and labview. We using proteus simulator for simulating the sensor and arduino hardware. The hardware that we use are pressure sensor and arduino uno. The concept of flowrate calculation system is using this formula:

![image](https://user-images.githubusercontent.com/92786679/141994190-a9377df6-0118-4c51-ad67-f240b4d97a78.png)

Where,

α1 =  Coefficient of linearity temperature expansion on orifice plate

Tr = Temperature of orifice plate

Tf = Temperature of gas flow

dr =  diameter of orifice plate when its initial temperature is Tr

d = diameter of orifice plate when its temperature is Tf

Cd = Coefficient of orifice pit

ΔP = Pressure differential on orifice

Ev = Velocity of fluid

gc = Dimensional conversion coefficient

π = 3.14

qm = Flowrate

ρt.p = Fluid density with reference from temperature and pressure

Y = Expansion factor


The hardware scheme like this:

![image](https://user-images.githubusercontent.com/92786679/141996489-b7ca022d-cf83-4bc5-9b2b-2b51a533255b.png)

The labview scheme like this:

![image](https://user-images.githubusercontent.com/92786679/141996549-29370ef0-3003-4ef8-bd32-22a1e46983e8.png)
![image](https://user-images.githubusercontent.com/92786679/141996567-80424490-d7af-42ce-9995-803e43b928b3.png)

