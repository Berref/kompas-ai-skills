# MultiThicknessGroupsObjects - Объекты в группе

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IMultiThicknessGroupsManager ](imultithicknessgroupsmanager.html) > [IMultiThicknessGroupsManager - свойства ](imultithicknessgroupsmanager_propers.html) |  Scroll [ [ [ ](imultithicknessgroupsmanager_multithicknessgroupsthickness.html "К следующему разделу")](imultithicknessgroupsmanager_propers.html "На уровень выше")](imultithicknessgroupsmanager_multithicknessgroupscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultithicknessgroupsmanager.html)

Тип данных: VARIANT

Синтаксис Automation:

MultiThicknessGroupsObjects = Object.MultiThicknessGroupsObjects( Type, Index ) | Получить свойство ([* ](1.html))  
---|---  
Object.MultiThicknessGroupsObjects( Type, Index ) = MultiThicknessGroupsObjects | Установить свойство ([* ](1.html))  
MultiThicknessGroupsObjects = Object.GetMultiThicknessGroupsObjects( Type, Index ) | Получить свойство ([**](2.html))  
Object.SetMultiThicknessGroupsObjects( Type, Index, MultiThicknessGroupsObjects ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_MultiThicknessGroupsObjects( Type, Index, &MultiThicknessGroupsObjects ) | Получить свойство  
---|---  
Object.put_MultiThicknessGroupsObjects( Type, Index, MultiThicknessGroupsObjects ) | Установить свойство  
  
Входные параметры:

Type | \- Тип группы параметров из перечисления [ksMultiThicknessGroupTypeEnum](ksmultithicknessgrouptypeenum.html),  
---|---  
long Index | \- Индекс параметров в группе.  
  
Подразделы:

(отсутствуют)
