# ReleaseReference - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference p = LineSeg (100, 50, 200, 50, 1);

LightObj (p, 1);

/освобождается указатель на объект,

/после вызова ReleaseReference к объекту р обращаться нельзя

ReleaseReference (p);

LightObj (p, 0);

//взводится ошибка "В текущем документе объект не найден"

MessageBoxResult();
