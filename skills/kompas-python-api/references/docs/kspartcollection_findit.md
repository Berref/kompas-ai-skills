# FindIt - Получить индекс элемента в массиве

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Массив компонентов сборки (Интерфейсы ksPartCollection и IPartCollection) ](kspartcollection.html) > [ksPartCollection - методы ](kspartcollection_methods.html) |  Scroll [ [ [ ](kspartcollection_first.html "К следующему разделу")](kspartcollection_methods.html "На уровень выше")](kspartcollection_getcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspartcollection.html)

Синтаксис Automation:

long FindIt(LPDISPATCH entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
-1 | \- если элемент не найден.  
  
Синтаксис COM:

unsigned long FindIt (LPPART entity);

Возвращаемое значение:

индекс элемента | \- если элемент найден в массиве,  
---|---  
SYS_MAX_UINT | \- если элемент не найден.  
  
Входные параметры:

entity | \- указатель на интерфейс компонента [ksPart](kspart.html) или [IPart](kspart.html).  
---|---  
  
Подразделы:

(отсутствуют)
