# GetEdgePointParams - Получение параметров ребер

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Листовое тело ](bc2753655.html) > [Интерфейс ISheetMetalContainer ](isheetmetalcontainer.html) > [ISheetMetalContainer - свойства ](isheetmetalcontainer_props.html) > [Интерфейс ISheetMetalLinearRuledShell ](isheetmetallinearruledshell.html) > [ISheetMetalLinearRuledShell - методы ](isheetmetallinearruledshell_methods.html) |  Scroll [ [ [ ](isheetmetallinearruledshell_setedgepointparam.html "К следующему разделу")](isheetmetallinearruledshell_methods.html "На уровень выше")](isheetmetallinearruledshell_getedgepointparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isheetmetallinearruledshell.html)

Синтаксис Automation:

BOOL GetEdgePointParams( VARIANT * Points1, VARIANT * T1, VARIANT * AssociateVertexes1, VARIANT * Points2, VARIANT * T2, VARIANT * AssociateVertexes2 );

Синтаксис COM :

HRESULT GetEdgePointParams( VARIANT * Points1, VARIANT * T1, VARIANT * AssociateVertexes1, VARIANT * Points2, VARIANT * T2, VARIANT * AssociateVertexes2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Выходные параметры:

Points1 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 начальных координат вершин.  
---|---  
T1 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 параметров вершин.  
AssociateVertexes1 | \- массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH вершин первой направляющей, связанных с вершинами.  
Points2 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 координат вершин ребер на второй направляющей.  
T2 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 параметров вершин ребер на первой направляющей.  
AssociateVertexes2 | массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH вершин второй направляющей, связанных с вершинами.  
  
Подразделы:

(отсутствуют)
