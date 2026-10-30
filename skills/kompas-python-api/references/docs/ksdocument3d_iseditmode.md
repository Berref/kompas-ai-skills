# IsEditMode - Определить, запущен ли какой-либо из компонентов на редактирование через библиотеку

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_ksdeleteobj.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_isdetail.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL IsEditMode();

Синтаксис COM:

BOOL IsEditMode();

Возвращаемое значение:

TRUE | \- редактирование компонента через библиотеку,  
---|---  
FALSE | \- редактируемых компонентов нет.  
  
Примечание:

Редактируемый компонент можно получить методом [GetPart](ksdocument3d_getpart.html) (pEdit_Part).

Подразделы:

(отсутствуют)
