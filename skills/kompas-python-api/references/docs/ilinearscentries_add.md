# Add - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ILinearsCentries ](ilinearscentries.html) > [ILinearsCentries - методы ](ilinearscentries_methods.html) |  Scroll [ [ [ ](icutlines.html "К следующему разделу")](ilinearscentries_methods.html "На уровень выше")](ilinearscentries_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinearscentries.html)

Синтаксис Automation:

LPDISPATCH Add( VARIANT BaseObjects, BOOL AutoFindOtherObjects, BOOL HasBreaks, double AxisAngle, double TurnAngle );

Синтаксис COM:

HRESULT Add( VARIANT BaseObjects, BOOL AutoFindOtherObjects, BOOL HasBreaks, double AxisAngle, double TurnAngle, ILinearCentres * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ILinearCentres](ilinearcentres.html).  
---|---  
  
Входные параметры:

BaseObjects | \- Базовые окружности.  
---|---  
AutoFindOtherObjects | \- Автоматический поиск других подходящих окружностей, центры которых лежат на круговой осевой линии.  
HasBreaks | \- С разрывами.  
AxisAngle | \- Наклон первой оси.  
TurnAngle | \- Угол раствора.  
  
Подразделы:

(отсутствуют)
