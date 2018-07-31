#!/bin/bash

TARGET=ode

hoge=`echo "scale=8; 2^-8"|bc`
hogE=`echo "scale=12; 2^-12"|bc`
hoGe=`echo "scale=16; 2^-16"|bc`

cat $TARGET.ode | ode -E $hoge > e28
cat $TARGET.ode | ode -E $hogE > e212
cat $TARGET.ode | ode -E $hoGe > e216

graph -T png -C -L 'euler' e28 e212 e216 > euler.png

cat $TARGET.ode | ode -A $hoge > a28
cat $TARGET.ode | ode -A $hogE > a212
cat $TARGET.ode | ode -A $hoGe > a216

graph -T png -C -L 'adamsMoulton' a28 a212 a216 > adams.png

rm ?2*
