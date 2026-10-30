# filterCPlanes - Фильтровать конструктивные плоскости

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ksobjectsfilter3d_filteredges.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_filtercaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию конструктивных плоскостей,  
---|---  
FALSE | \- запретить фильтрацию конструктивных плоскостей.  
  
Синтаксис Automation:

filterCPlanes = iObjFilter3D.filterCPlanes; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterVertexs = filterCPlanes; | Установить свойство ([* ](1.html))  
filterCPlanes = iObjFilter3D.GetFilterCPlanes(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterCPlanes(filterCPlanes); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterCPlanes = iObjFilter3D.GetFilterCPlanes(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterCPlanes(filterCPlanes); | Установить свойство  
  
Примечание:

1\. После установки свойства равным TRUE флаг [Фильтровать все](ksobjectsfilter3d_filterall.html) снимается.

2\. Если после установки флага равным FALSE все флаги для типов объектов окажутся равными FALSE, то будет включено свойство Фильтровать все.

Подразделы:

(отсутствуют)
