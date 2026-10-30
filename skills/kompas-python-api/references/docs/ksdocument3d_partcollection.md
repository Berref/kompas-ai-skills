# PartCollection - Получить указатель на интерфейс динамического массива компонентов, вставленных в сборку

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_placefeatureafter.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_open.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

LPDISPATCH PartCollection (BOOL refresh)

Синтаксис COM:

LPPARTCOLLECTION PartCollection (BOOL refresh);

Входные параметры:

refresh | \- TRUE - полученный массив будет заполнен компонентами данной сборки или детали, \- FALSE - полученный массив будет пустым.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс динамического массива компонентов, вставленных в сборку [ksPartCollection](kspartcollection.html) или [IPartCollection](kspartcollection.html).  
---|---  
  
Подразделы:

(отсутствуют)
