# Code - Код ошибки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Информация об ошибках ](ap1713366.html) > [Интерфейс IKompasError ](ikompaserror.html) > [IKompasError - свойства ](ikompaserror_props.html) |  Scroll [ [ [ ](ikompaserror_description.html "К следующему разделу")](ikompaserror_props.html "На уровень выше")](ikompaserror_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaserror.html)

Тип данных: из перечисления [ErrorType](errortype.html) и [ErrorType3d](errortype3d.html).

Синтаксис Automation:

Code = iObject.Code | Получить свойство ([* ](1.html))  
---|---  
Code = iObject.GetCode() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Code (&Code) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения. Так как коды ошибок из [ErrorType](errortype.html) и [ErrorType3d](errortype3d.html) пересекаются, то для определения из какого перечисления взведена ошибка, нужно воспользоваться свойством [Error3D](ikompaserror_error3d.html).

Подразделы:

(отсутствуют)
