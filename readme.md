
O objetivo deste trabalho é aplicar o conceito de filas computacionais para simular o atendimento das filas de clientes em caixas de agências bancárias.

A agência é composta basicamente de três entidades: cliente (que fazem fila para ser atendidos); caixa (o local físico); e atendente de caixa (a pessoa que atende).

- A agência bancária abre as 10 horas da manhã e fecha as 16 horas. Portanto, a agência fica aberta por 6h durante o dia.

- Devem existir duas filas: uma preferencial (para idosos, aposentados, gestantes, deficientes físicos, etc.) e outra normal (para os clientes não preferencial);

- Os atendentes devem sempre dar prioridade a cliente preferencial. Todavia após o atendimento consecutivo de dois clientes preferencial, o caixa deve atender um cliente não preferencial. Exceção: caso a fila de clientes não preferencial esteja vazia, o atendente pode continuar prestando serviços aos clientes preferenciais.