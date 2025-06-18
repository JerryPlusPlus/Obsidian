[`PreTrainedTokenizerFast`] 依赖于 [🤗 Tokenizers](https://huggingface.co/docs/tokenizers) 库。从 🤗 Tokenizers 库获得的分词器可以被轻松地加载到 🤗 Transformers 中。

在了解具体内容之前，让我们先用几行代码创建一个虚拟的分词器：

```python
>>> from tokenizers import Tokenizer
>>> from tokenizers.models import BPE
>>> from tokenizers.trainers import BpeTrainer
>>> from tokenizers.pre_tokenizers import Whitespace

>>> tokenizer = Tokenizer(BPE(unk_token="[UNK]"))
>>> trainer = BpeTrainer(special_tokens=["[UNK]", "[CLS]", "[SEP]", "[PAD]", "[MASK]"])

>>> tokenizer.pre_tokenizer = Whitespace()
>>> files = [...]
>>> tokenizer.train(files, trainer)
```

现在，我们拥有了一个针对我们定义的文件进行训练的分词器。我们可以在当前运行时中继续使用它，或者将其保存到一个 JSON 文件以供将来重复使用。

## 直接从分词器对象加载

让我们看看如何利用 🤗 Transformers 库中的这个分词器对象。[`PreTrainedTokenizerFast`] 类允许通过接受已实例化的 *tokenizer* 对象作为参数，进行轻松实例化：

```python
>>> from transformers import PreTrainedTokenizerFast

>>> fast_tokenizer = PreTrainedTokenizerFast(tokenizer_object=tokenizer)
```

现在可以使用这个对象，使用 🤗 Transformers 分词器共享的所有方法！前往[分词器页面](main_classes/tokenizer)了解更多信息。

## 从 JSON 文件加载

为了从 JSON 文件中加载分词器，让我们先保存我们的分词器：

```python
>>> tokenizer.save("tokenizer.json")
```

我们保存此文件的路径可以通过 `tokenizer_file` 参数传递给 [`PreTrainedTokenizerFast`] 初始化方法：

```python
>>> from transformers import PreTrainedTokenizerFast

>>> fast_tokenizer = PreTrainedTokenizerFast(tokenizer_file="tokenizer.json")
```

现在可以使用这个对象，使用 🤗 Transformers 分词器共享的所有方法！前往[分词器页面](main_classes/tokenizer)了解更多信息。