# AddByPoint - Создает новый элемент и добавляет его в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Коллекции обозначений ](bb3219842.html) > [Интерфейс ICircularsCentries ](icircularscentries.html) > [ICircularsCentries - методы ](icircularscentries_methods.html) |  Scroll [ [ [ ](iconditionintersects.html "К следующему разделу")](icircularscentries_methods.html "На уровень выше")](icircularscentries_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icircularscentries.html)

Синтаксис Automation:

LPDISPATCH AddByPoint( double X0, double Y0, VARIANT BaseObjects, BOOL AutoFindOtherObjects, BOOL Closed, BOOL WithCenter );

Синтаксис COM:

HRESULT AddByPoint( double X0, double Y0, VARIANT BaseObjects, BOOL AutoFindOtherObjects, BOOL Closed, BOOL WithCenter, ICircularCentres * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ICircularCentres](icircularcentres.html).  
---|---  
  
Входные параметры:

X0, Y0 | \- Координаты цента осевой линии.  
---|---  
BaseObjects | \- Базовые окружности.  
AutoFindOtherObjects | \- Автоматический поиск других подходящих окружностей, центры которых лежат на круговой осевой линии.  
Closed | \- Замкнуть осевую.  
WithCenter | \- С обозначением центра.  
  
Примечание

Радиус обозначения центра определяется по удалению точки центра первой окружности.

Для остальных окружностей выполняется проверка на одинаковое расстояние от точки центра осевой линии до центра окружности.

Подразделы:

(отсутствуют)
