# SetCurrent - Установить данную проекцию отображения модели в окне текущей

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейс коллекции проекций отображения модели (Интерфейсы ksViewProjectionCollection, IViewProjectionCollection) ](ksviewprojectioncollection.html) > [Проекции отображения модели в окне (Интерфейсы ksViewProjection, IViewProjection) ](ksviewprojection.html) > [IViewProjection - методы ](ksviewprojection_methods.html) |  Scroll [ [ [ ](ksviewprojection_setmatrix3d.html "К следующему разделу")](ksviewprojection_methods.html "На уровень выше")](ksviewprojection_iscurrent.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksviewprojection.html)

Синтаксис Automation:

BOOL SetCurrent();

Синтаксис COM:

BOOL SetCurrent();

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Для проекции с индексом vp_NormalTo необходимо, чтобы в модели был выбран хотя бы один плоский объект.

2\. Для проекции с индексом vp_None модель разворачивается и масштабируется в соответствии с заданными параметрами проекции. Сама проекция в массив не добавляется.

Подразделы:

(отсутствуют)
