# filterCAxis - Фильтровать конструктивные оси

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ksobjectsfilter3d_filtercplanes.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_filterall.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию конструктивных осей,  
---|---  
FALSE | \- запретить фильтрацию конструктивных осей.  
  
Синтаксис Automation:

filterCAxis = iObjFilter3D.filterCAxis; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterCAxis = filterCAxis; | Установить свойство ([* ](1.html))  
filterCAxis = iObjFilter3D.GetFilterCAxis(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterCAxis(filterCAxis); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterCAxis = iObjFilter3D.GetFilterCAxis(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterCAxis(filterCAxis); | Установить свойство  
  
Примечание:

1\. После установки свойства равным TRUE флаг [Фильтровать все](ksobjectsfilter3d_filterall.html) снимается.

2\. Если после установки флага равным FALSE все флаги для типов объектов окажутся равными FALSE, то будет включено свойство Фильтровать все.

Подразделы:

(отсутствуют)
