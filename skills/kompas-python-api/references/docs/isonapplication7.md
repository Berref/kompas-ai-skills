# IsOnApplication7 - Получить тип версии API, используемого библиотекой

[Создание прикладных библиотек ](libraries_create.html) > [Оформление прикладных библиотек типа ActiveX ](cr119224.html) > [Пример простейшей программы в среде VB, оформленной в виде ActiveX библиотеки КОМПАС ](simple_sample_ax.html) > [Функции ](cr154576.html) |  Scroll [ [ [ ](externalgetresourcemodule.html "К следующему разделу")](cr154576.html "На уровень выше")](displaylibraryname_2.html "К предыдущему разделу")  
---|---  
  
VARIANT_BOOL IsOnApplication7();

Возвращаемое значение:

TRUE | \- библиотека использует API версии 7,  
---|---  
FALSE | \- библиотека использует API версии 5.  
  
Примечание:

Необязательный метод оформления библиотеки. Позволяет задать тип интерфейса, который будет передан библиотеке в параметре kompas метода [ExternalRunCommand](externalruncommand.html) и в параметре application метода [LibInterfaceNotifyEntry](libinterfacenotifyentry.html). Если метод в библиотеке не объявлен, то считается что библиотека использует API версии 5.

Подразделы:

(отсутствуют)
