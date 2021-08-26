# calibration
You have to calibrate every measuring equipment in order to be accurate.In the HX711's datasheet mentioned that this module is linear but it is important you have a line like y = ax+b. So you should find a and b to have correct results.

## how does this code work?
First of all we have the weight of surfaces so the function **scale.tare()** find the parameter b in previous part and set it to zero. Then for finding a, put a known weight on the scale and by sending **+** or **-** set the calibration factor.

## what should we do?
1. upload the calibration code
2. Don't put anything until you see a message that you should put a known weight
3. Put a known weight on the scale
4. Change calibration factor till you get right weight