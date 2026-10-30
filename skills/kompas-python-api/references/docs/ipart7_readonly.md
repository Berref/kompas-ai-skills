# ReadOnly - Тип доступа к компоненту

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - свойства ](ipart7_props.html) |  Scroll [ [ [ ](ipart7_revealcomposition.html "К следующему разделу")](ipart7_props.html "На уровень выше")](ipart7_propertyobjecteditable.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Тип данных: из перечисления [ksPartAccessTypeEnum](kspartaccesstypeenum.html)

Синтаксис Automation:

ReadOnly = Object.ReadOnly | Получить свойство ([* ](1.html))  
---|---  
Object.ReadOnly = ReadOnly | Установить свойство ([* ](1.html))  
ReadOnly = Object.GetReadOnly() | Получить свойство ([**](2.html))  
Object.SetReadOnly( ReadOnly ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ReadOnly( &ReadOnly ) | Получить свойство  
---|---  
Object.put_ReadOnly( ReadOnly ) | Установить свойство  
  
Свойство позволяет устанавливать и получать тип доступа к компоненту.

Примечание:

Тип ksATDisable установить нельзя. Он возвращается в том случае, если смена доступа защищена паролем.

Подразделы:

(отсутствуют)
