# IsEnableTaskAccess - пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//проверяем доступ к задаче

bool flagEnableTaskAccess = IsEnableTaskAccess();

Message (flagEnableTaskAccess ? "Доступ разрешен" : "Доступ запрещен");

if (flagEnableTaskAccess)

{

//запрещаем доступ

EnableTaskAccess (0);

//проверяем доступ к задаче

flagEnableTaskAccess = IsEnableTaskAccess();

Message (flagEnableTaskAccess ? "Доступ разрешен" : "Доступ запрещен");

EnableTaskAccess (1); // разрешить доступ

}
