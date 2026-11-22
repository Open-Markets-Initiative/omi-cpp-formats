# parquet

Each directory below holds one way of writing `parquet`, with a ReadMe showing how to use its programs, how they are tested, and its organizations and protocols. Every one reads its captures through the Advanced parser under `cpp/advanced/`.

## Formats

| Format | Description | Protocols | Generated Lines |
| --- | --- | ---: | ---: |
| [wide parquet](wide) | One table per protocol, a column for every value any of its messages holds. It needs `libarrow-dev` and `libparquet-dev` (on Ubuntu). | 25 | 36,624 |

