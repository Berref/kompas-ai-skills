# GetMainBody - Получить указатель на интерфейс результирующего тела

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [IPart - методы ](kspart_methods.html) |  Scroll [ [ [ ](kspart_getmass.html "К следующему разделу")](kspart_methods.html "На уровень выше")](kspart_getgabarit.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kspart.html)

Синтаксис Automation:

LPDISPATCH GetMainBody();

Синтаксис COM:

LPBODY GetMainBody();

Возвращаемое значение:

| \- указатель на интерфейс [ksBody](ksbody.html) или [IBody](ksbody.html).  
---|---  
  
Пример:

Деталь имеет массив интерфейсов тел IBody. Используя этот массив интерфейсов, можно получить доступ к математической модели детали (компонента).

Подразделы:

(отсутствуют)
