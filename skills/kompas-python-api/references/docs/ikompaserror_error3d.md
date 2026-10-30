# Error3D - Ошибка для 3D

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Информация об ошибках ](ap1713366.html) > [Интерфейс IKompasError ](ikompaserror.html) > [IKompasError - свойства ](ikompaserror_props.html) |  Scroll [ [ [ ](ikompaserror_methods.html "К следующему разделу")](ikompaserror_props.html "На уровень выше")](ikompaserror_description.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaserror.html)

Тип данных:BOOL.

Синтаксис Automation:

Error3D = iObject.Error3D | Получить свойство ([* ](1.html))  
---|---  
Error3D = iObject.GetError3D() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_Error3D (&Error3D) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- ошибка возникла в 3D API (перечисление [ErrorType3d](errortype3d.html)),  
---|---  
FALSE | \- ошибка из перечисления [ErrorType](errortype.html).  
  
Примечание:

Свойство доступно только для чтения. Позволяет определить, какому из двух перечислений соответствует код ошибки, полученный через свойство [Code](ikompaserror_code.html)

Подразделы:

(отсутствуют)
