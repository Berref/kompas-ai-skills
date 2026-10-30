# ObjectError - Получить номер ошибки

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IFeature7 ](ifeature7.html) > [IFeature7 - свойства ](ifeature7_props.html) |  Scroll [ [ [ ](ifeature7_ownerfeature.html "К следующему разделу")](ifeature7_props.html "На уровень выше")](ifeature7_name.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifeature7.html)

Тип данных: long

Синтаксис Automation:

ObjectError = Object.ObjectError | Получить свойство ([* ](1.html))  
---|---  
ObjectError = Object.GetObjectError() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ObjectError( &ObjectError ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Если на объекте взведено несколько ошибок, возвращается номер первой.

3\. Номера ошибок соответствуют перечислению [ErrorType3d](errortype3d.html).

Подразделы:

(отсутствуют)
