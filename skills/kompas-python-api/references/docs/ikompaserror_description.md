# Description - Описание ошибки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Информация об ошибках ](ap1713366.html) > [Интерфейс IKompasError ](ikompaserror.html) > [IKompasError - свойства ](ikompaserror_props.html) |  Scroll [ [ [ ](ikompaserror_error3d.html "К следующему разделу")](ikompaserror_props.html "На уровень выше")](ikompaserror_code.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompaserror.html)

Тип данных:BSTR (строка).

Синтаксис Automation:

Description = iObject.Description | Получить свойство ([* ](1.html))  
---|---  
Description = iObject.GetDescription() | Получить свойство([**](2.html))  
  
Синтаксис COM:

iObject->get_Description (&Description) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения. Позволяет получить символьное описание возникшей ошибки в системе КОМПАС. После выдачи описания ошибки она сбрасывается, т.е. устанавливается в etSuccess (Успешное завершение).

Подразделы:

(отсутствуют)
