# filterEdges - Фильтровать ребра

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ksobjectsfilter3d_filterfaces.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_filtercplanes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию ребер,  
---|---  
FALSE | \- запретить фильтрацию ребер.  
  
Синтаксис Automation:

filterEdges = iObjFilter3D.filterEdges; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterEdges = filterEdges; | Установить свойство ([* ](1.html))  
filterEdges = iObjFilter3D.GetFilterEdges(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterEdges(filterEdges); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterEdges = iObjFilter3D.GetFilterEdges(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterEdges(filterEdges); | Установить свойство  
  
Примечание:

1\. После установки свойства равным TRUE флаг [Фильтровать все](ksobjectsfilter3d_filterall.html) снимается.

2\. Если после установки флага равным FALSE все флаги для типов объектов окажутся равными FALSE, то будет включено свойство Фильтровать все.

Подразделы:

(отсутствуют)
