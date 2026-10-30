# ConvertCoordinates - Преобразовать оконные координаты в координаты СК согласно ConvertCoordTypeEnum

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_executekompascommand.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL ConvertCoordinates (ConvertCoordTypeEnum type,

long lx,

long ly,

double* x,

double* y,

double* z);

Синтаксис COM:

HRESULT ConvertCoordinates ([in]ConvertCoordTypeEnum type,

[in]long lx,

[in]long ly,

[out]double* x,

[out]double* y,

[out]double* z,

[out, retval]

VARIANT_BOOL* Result);

Входные параметры:

lx, ly | \- координаты в экранных пикселах,  
---|---  
type | \- тип СК в которую нужно преобразовать оконные координаты.  
  
Выходные параметры:

x, y, z | \- координаты в мм в СК согласно [ConvertCoordTypeEnum](convertcoordtypeenum.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- преобразование прошло успешно,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Получив координаты мыши в оконных координатах при обработке событий из ksDocumentFrameNotify:

frMouseDown | 3 | Нажатие кнопки мыши.  
---|---|---  
frMouseUp | 4 | Отпускание кнопки мыши.  
frMouseDblClick | 5 | Двойной щелчок мыши.  
frMouseMove | 12 | Перемещение мыши.  
  
их можно преобразовать в системы координат, указанные в [ConvertCoordTypeEnum](convertcoordtypeenum.html):

•для графических документов можно получить координаты в СК листа и текущего вида,

•для СП и текстового документа в СК первого листа,

•для модели в СК документа и в СК текущей плоской грани. Грань должна быть выделена в дереве.

2\. Если курсор находится в нерабочей области окна активного документа, то конвертация координат не производится, возвращается FALSE. Нерабочей областью окна является, например, панель команд или панель свойств в этом же активном документе.

См. также [ConvertCoordTypeEnum](convertcoordtypeenum.html)

Подразделы:

(отсутствуют)
