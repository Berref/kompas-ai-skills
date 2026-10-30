# filterAll - Фильтровать все

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ksobjectsfilter3d_filtercaxis.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию для всех типов объектов,  
---|---  
FALSE | \- фильтрация разрешена только для конкретных типов объектов.  
  
Синтаксис Automation:

filterAll = iObjFilter3D.filterAll; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterAll = filterAll; | Установить свойство ([* ](1.html))  
filterAll = iObjFilter3D.GetFilterAll(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterAll(filterAll); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterAll = iObjFilter3D.GetFilterAll(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterAll(filterAll); | Установить свойство  
  
Примечание:

Напрямую установить свойство равным FALSE нельзя. Свойство устанавливается равным FALSE после установки любых флагов для конкретных типов объектов.

Подразделы:

(отсутствуют)
