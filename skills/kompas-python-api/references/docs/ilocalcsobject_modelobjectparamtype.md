# ModelObjectParamType - Тип параметров объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс ILocalCSObject ](ilocalcsobject.html) > [ILocalCSObject - свойства ](ilocalcsobject_props.html) |  Scroll [ [ [ ](ilocalcsobject_localcoordinatesystem.html "К следующему разделу")](ilocalcsobject_props.html "На уровень выше")](ilocalcsobject_coordinatesystem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcsobject.html)

Тип данных: из перечисления [ksModelObjectParamTypeEnum](ksmodelobjectparamtypeenum.html)

Синтаксис Automation:

ModelObjectParamType = Object.ModelObjectParamType | Получить свойство ([* ](1.html))  
---|---  
Object.ModelObjectParamType = ModelObjectParamType | Установить свойство ([* ](1.html))  
ModelObjectParamType = Object.GetModelObjectParamType() | Получить свойство ([**](2.html))  
Object.SetModelObjectParamType( ModelObjectParamType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ModelObjectParamType( &ModelObjectParamType ) | Получить свойство  
---|---  
Object.put_ModelObjectParamType( ModelObjectParamType ) | Установить свойство  
  
Примечание:

Свойство позволяет установить тип параметров объекта.

После установки данного свойства параметры объекта будут выдаваться пересчитанными в установленную систему координат. При установке параметров также будет производиться пересчет параметров. Для правильной работы библиотек требуется установить нужный тип параметров, получить или изменить параметры и вернуть тип параметров ksMOPartAllParam-Параметры в системе координат детали (см. [ksModelObjectParamTypeEnum](ksmodelobjectparamtypeenum.html) -Тип параметров объекта).

Подразделы:

(отсутствуют)
