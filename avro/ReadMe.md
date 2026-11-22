# avro

Each directory below holds one way of writing `avro`, with a ReadMe showing how to use its programs, how they are tested, and its organizations and protocols. Every one reads its captures through the Advanced parser under `cpp/advanced/`.

## Formats

| Format | Description | Protocols | Generated Lines |
| --- | --- | ---: | ---: |
| [wide avro (native)](wide/native) | Every message as one wide record of the values any message holds, written without an Avro library. It needs nothing beyond the compiler. | 25 | 31,842 |
| [wide avro (c)](wide/c) | Every message as one wide record of the values any message holds, written through Apache Avro's C library. It needs `libavro-dev` (on Ubuntu). | 25 | 31,760 |
| [tree avro (native)](tree/native) | Every message as a record of its own, holding what it holds as the model declares it, written without an Avro library. It needs nothing beyond the compiler. | 25 | 11,181 |
| [tree avro (c)](tree/c) | Every message as a record of its own, holding what it holds as the model declares it, written through Apache Avro's C library. It needs `libavro-dev` (on Ubuntu). | 25 | 11,099 |

