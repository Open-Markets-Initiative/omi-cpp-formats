# json

Each directory below holds one way of writing `json`, with a ReadMe showing how to use its programs, how they are tested, and its organizations and protocols. Every one reads its captures through the Advanced parser under `cpp/advanced/`.

## Formats

| Format | Description | Protocols | Generated Lines |
| --- | --- | ---: | ---: |
| [native json](native) | Writers that turn every message into a flat JSON object without a JSON library. It needs nothing beyond the compiler. | 25 | 10,762 |
| [rapid json](rapid) | Writers that turn every message into the same object through RapidJSON. It needs `rapidjson-dev` (on Ubuntu). | 25 | 11,179 |

