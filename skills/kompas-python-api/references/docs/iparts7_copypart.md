# CopyPart - Создать копию заданного компонента с заданным положением

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_createdocument.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_addfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation:

LPDISPATCH CopyPart( IPart7 * SourcePart, IPlacement3D * NewPlacement );

Синтаксис COM:

HRESULT CopyPart( IPart7 * SourcePart, IPlacement3D * NewPlacement, IPart7 * * Result );

Возвращаемое значение:

| \- указатель на интерфейс компонента I[Part7](ipart7.html),  
---|---  
  
Входные параметры:

SourcePart | \- копируемая вставка [IPart7](ipart7.html),  
---|---  
NewPlacement | \- указатель на интерфейс положения создаваемой копии [IPlacement3D](iplacement3d.html).  
  
Версия Компас v23

Подразделы:

(отсутствуют)
