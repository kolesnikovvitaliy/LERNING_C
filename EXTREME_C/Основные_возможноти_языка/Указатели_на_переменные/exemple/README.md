graph TD
    %% Стилизация элементов
    classDef base fill:#1a365d,stroke:#2b6cb0,stroke-width:2px,color:#fff;
    classDef memory fill:#2d3748,stroke:#4a5568,stroke-width:1px,color:#a0aec0;
    classDef active fill:#22543d,stroke:#48bb78,stroke-width:2px,color:#fff;
    classDef step fill:#744210,stroke:#d69e2e,stroke-width:2px,color:#fff;
    classDef scenario fill:#4a1285,stroke:#9f7aea,stroke-width:1px,color:#fff;

    %% Раздел структуры памяти
    subgraph memoryStructure ["1. Физическое представление памяти"]
        M0[" Элемент <br> Адрес: Base"]:::base
        M1[" Элемент <br> Адрес: Base + 1*Size"]:::memory
        M2[" Текущий Шаг <br> Адрес: Base + 2*Size"]:::active
        M3[" Конец <br> Адрес: Base + 3*Size"]:::memory
    end

    %% Раздел логики управления
    subgraph controlLogic ["2. Механизм адресации"]
        BasePtr["array_ptr <br> (НЕИЗМЕННЫЙ)"]:::base
        LenStep["len_step_ptr = 2 <br> (ПЕРЕМЕННЫЙ ШАГ)"]:::step

        BasePtr -->|0-е смещение| M0
        LenStep -->|Математический сдвиг| M2
        BasePtr -.-> |Формула: Base + len_step_ptr| M2
    end

    %% Раздел вариантов использования
    subgraph useCases ["3. Сценарии использования паттерна"]
        S1["🛡️ Safe Iteration <br> Безопасный перебор данных"]:::scenario
        S2["🔄 Window Processing <br> Обработка 'скользящим окном'"]:::scenario
        S3["📁 File/Network Buffers <br> Чтение пакетов со смещением"]:::scenario
        S4["📊 Multi-pass Algorithms <br> Алгоритмы сортировки"]:::scenario
    end

    %% Связь механизмов со сценариями
    M2 --> S1
    LenStep --> S2
    LenStep --> S3
    BasePtr --> S4

    %% Стилизация подграфов по их латинским ID
    style memoryStructure fill:#11141a,stroke:#2d3748,color:#fff
    style controlLogic fill:#11141a,stroke:#2d3748,color:#fff
    style useCases fill:#1b1522,stroke:#4a1285,color:#fff
