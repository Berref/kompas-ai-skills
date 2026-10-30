# ksCreateViewObject, ksEditViewObject - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
// создать объект в интерактивном режиме (позиционная линия выноски)

reference posLeader = ksCreateViewObject(POSLEADER_OBJ );

if (posLeader){

LightObj(posLeader, 1);

Message("Позиционная линия выноски");

LightObj(posLeader, 0);

if (ksEditViewObject(posLeader)) {

LightObj(posLeader, 1);

Message("Отредактированная позиционная линия выноски");

LightObj(posLeader, 0);

}

}
