# PickObjects - Собрать объекты по лучу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IExternalTessellationManager ](iexternaltessellationmanager.html) > [IExternalTessellationManager - методы ](iexternaltessellationmanager_methods.html) |  Scroll [ [ [ ](iexternaltessellationobject.html "К следующему разделу")](iexternaltessellationmanager_methods.html "На уровень выше")](iexternaltessellationmanager_deletetextureimage.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iexternaltessellationmanager.html)

Синтаксис Automation:

BOOL PickObjects( LPDISPATCH Frame, VARIANT PickRay, BOOL Visible, VARIANT * PickedObjs, VARIANT * PickedPars );

Синтаксис COM:

HRESULT PickObjects( IDocumentFrame * Frame, VARIANT PickRay, BOOL Visible, VARIANT * PickedObjs, VARIANT * PickedPars, BOOL * Result) ;

Входные параметры:

Frame | \- Указатель на интерфейс окна документа [IDocumentFrame](idocumentframe.html),  
---|---  
PickRay | \- Параметры луча ( VT_ARRAY | VT_R8 ), массив из шести элементов (Точка начала луча и единичный вектор задающий направление луча),  
Visible | \- Признак учета видимых объектов: TRUE - пересекать только с видимыми объектами, FALSE - со всеми объектами.  
  
Выходные параметры:

PickedObjs | \- Идентификаторы найденных внешних объектов триангуляции (VT_ARRAY | VT_UI4),  
---|---  
PickedPars | \- Параметры луча в точке пересечения с объектами (VT_ARRAY | VT_R4).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
