# avro/wide

Each directory below holds one way of writing `avro/wide`, with a ReadMe showing how to use its programs, how they are tested, and its organizations and protocols. Every one reads its captures through the Advanced parser under `cpp/advanced/`.

## Formats

| Format | Description | Protocols | Generated Lines |
| --- | --- | ---: | ---: |
| [wide avro (native)](native) | Every message as one wide record of the values any message holds, written without an Avro library. It needs nothing beyond the compiler. | 25 | 31,842 |
| [wide avro (c)](c) | Every message as one wide record of the values any message holds, written through Apache Avro's C library. It needs `libavro-dev` (on Ubuntu). | 25 | 31,760 |

