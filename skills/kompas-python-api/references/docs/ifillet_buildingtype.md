# BuildingType - Способ построения скругления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IFillet ](ifillet.html) > [IFillet - свойства ](ifillet_propers.html) |  Scroll [ [ [ ](ifillet_chord.html "К следующему разделу")](ifillet_propers.html "На уровень выше")](ifillet_baseobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ifillet.html)

Тип данных: Значение из перечисления [ksFilletBuildingTypeEnum](ksfilletbuildingtypeenum.html).

Синтаксис Automation:

BuildingType = Object.BuildingType | Получить свойство ([* ](1.html))  
---|---  
Object.BuildingType = BuildingType | Установить свойство ([* ](1.html))  
BuildingType = Object.GetBuildingType() | Получить свойство ([**](2.html))  
Object.SetBuildingType( BuildingType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BuildingType( &BuildingType ) | Получить свойство  
---|---  
Object.put_BuildingType( BuildingType ) | Установить свойство  
  
Примечание.

Метод позволяет получать и устанавливать опорный объект или массив опорных объектов, участвующих в операции Скругление.

Массив объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Подразделы:

(отсутствуют)
