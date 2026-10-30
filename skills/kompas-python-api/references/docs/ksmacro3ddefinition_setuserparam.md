# SetUserParam - Установить параметры пользователя

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Объект модели (Интерфейсы ksEntity и IEntity) ](bw1897880.html) > [Интерфейсы ksEntity и iEntity - Интерфейс элемента модели (оси, плоскости, формообразующего элемента) ](ksentity.html) > [Интерфейсы поверхностей ](nt_surface.html) > [Интерфейс макроэлемента (ksMacro3DDefinition, IMacro3DDefinition) ](ksmacro3ddefinition.html) > [IMacro3DDefinition - методы ](ksmacro3ddefinition_methods.html) |  Scroll [ [ [ ](ksunioncomponentsdefinition.html "К следующему разделу")](ksmacro3ddefinition_methods.html "На уровень выше")](ksmacro3ddefinition_setobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmacro3ddefinition.html)

Синтаксис Automation:

BOOL SetUserParam (LPDISPATCH userPars);

Входные параметры:

userPars | \- указатель на интерфейс пользовательских параметров [ksUserParam](ksuserparam.html).  
---|---  
  
Синтаксис COM:

BOOL SetUserParam (void *value,

unsigned int size,

LPOLESTR nameFile,

LPOLESTR nameLib,

int number );

Входные параметры:

value | \- указатель на пользовательскую структуру параметров,  
---|---  
size | \- размер структуры параметров,  
nameFile | \- имя файла прикладной библиотеки для последующего редактирования через библиотеку (0 - запоминается текущая библиотека),  
nameLib | \- имя прикладной библиотеки для последующего редактирования через библиотеку (0 - запоминается текущая библиотека),  
number | \- номер команды в прикладной библиотеке для последующего редактирования через библиотеку (-1 - запоминается текущая команда).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечания:

Данный метод позволяет сохранить параметры пользователя для последующего редактирования с помощью библиотеки.

Подразделы:

(отсутствуют)
