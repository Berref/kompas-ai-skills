# filterFaces - Фильтровать грани

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ksobjectsfilter3d_filtervertexs.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_filteredges.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию граней,  
---|---  
FALSE | \- запретить фильтрацию граней.  
  
Синтаксис Automation:

filterFaces = iObjFilter3D.filterFaces; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterFaces = filterFaces; | Установить свойство ([* ](1.html))  
filterFaces = iObjFilter3D.GetFilterFaces(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterFaces(filterFaces); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterFaces = iObjFilter3D.GetFilterFaces(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterFaces(filterFaces); | Установить свойство  
  
Примечание:

1\. После установки свойства равным TRUE флаг [Фильтровать все](ksobjectsfilter3d_filterall.html) снимается.

2\. Если после установки флага равным FALSE все флаги для типов объектов окажутся равными FALSE, то будет включено свойство Фильтровать все.

Подразделы:

(отсутствуют)
