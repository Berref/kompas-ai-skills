# GetDIBForOutput - Создать растровое изображение документа в объект «проекция файла» для дорисовки

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [OpenGL ](ba1848735.html) > [Интерфейс IPaintObject ](ipaintobject.html) > [IPaintObject - методы ](ipaintobject_methods.html) |  Scroll [ [ [ ](ipaintobject_gethwnd.html "К следующему разделу")](ipaintobject_methods.html "На уровень выше")](ipaintobject_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipaintobject.html)

Синтаксис Automation:

BSTR GetDIBForOutput();

Синтаксис COM:

HRESULT GetDIBForOutput ([out, retval] BSTR* mapFileName);

Возвращаемое значение:

Имя созданного объекта «проекция файла». | \- в случае успешного завершения.  
---|---  
  
Примечание:

Создает объект «проекция файла» (объект ядра в Windows, создаваемый для организации совместного использования несколькими процессами одних и тех же блоков данных) для возможности дорисовки своей геометрии к изображению документа.

Подразделы:

(отсутствуют)
