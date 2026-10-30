# filterVertexs - Фильтровать вершины

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейс фильтрации объектов документа-модели (Интерфейс ksObjectsFilter3D) ](ksobjectsfilter3d.html) > [IObjectsFilter3D - свойства ](ksobjectsfilter3d_props.html) |  Scroll [ [ [ ](ck1750127.html "К следующему разделу")](ksobjectsfilter3d_props.html "На уровень выше")](ksobjectsfilter3d_filterfaces.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksobjectsfilter3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- разрешить фильтрацию вершин,  
---|---  
FALSE | \- запретить фильтрацию вершин.  
  
Синтаксис Automation:

filterVertexs = iObjFilter3D.filterVertexs; | Получить свойство ([* ](1.html))  
---|---  
iObjFilter3D.filterVertexs = filterVertexs; | Установить свойство ([* ](1.html))  
filterVertexs = iObjFilter3D.GetFilterVertexs(); | Получить свойство ([**](2.html))  
iObjFilter3D.SetFilterVertexs(filterVertexs); | Установить свойство ([**](2.html))  
  
Синтаксис COM:

filterVertexs = iObjFilter3D.GetFilterVertexs(); | Получить свойство  
---|---  
iObjFilter3D.SetFilterVertexs(filterVertexs); | Установить свойство  
  
Примечание:

1\. После установки свойства равным TRUE флаг [Фильтровать все](ksobjectsfilter3d_filterall.html) снимается.

2\. Если после установки флага равным FALSE все флаги для типов объектов окажутся равными FALSE, то будет включено свойство Фильтровать все.

Подразделы:

(отсутствуют)
