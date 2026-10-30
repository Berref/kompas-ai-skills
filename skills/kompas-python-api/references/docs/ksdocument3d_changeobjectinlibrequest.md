# ChangeObjectInLibRequest - Изменить фантом или компоненты команд

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [ksDocument3D, IDocument3D - методы ](ksdocument3d_methods.html) |  Scroll [ [ [ ](ksdocument3d_close.html "К следующему разделу")](ksdocument3d_methods.html "На уровень выше")](ksdocument3d_attributecollection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument3d.html)

Синтаксис Automation:

BOOL ChangeObjectInLibRequest();

Синтаксис COM:

BOOL ChangeObjectInLibRequest();

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Вызов этого метода позволяет принудительно, не из CallBack-функции изменить параметры текущего процесса. Предварительно, используя интерфейс [ksRequestInfo3d](ksrequestinfo3d.html), можно изменить:

•состав команд командного окна,

•строку-приглашение,

•идентификатор или имя курсора,

•заголовок командного окна.

Все сделанные изменения будут активизированы сразу после вызова данной функции.

Процесс должен быть предварительно запущен функцией UserGetPlacementAndEntity.

Подразделы:

(отсутствуют)
